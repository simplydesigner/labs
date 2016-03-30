
#pragma once
#include <stdafx>
#include <iostream> 
#include <fstream> 

using namespace std;
class Matrix
{

public:
	Matrix();
	Matrix(int lines, int columns);
	Matrix(const Matrix& obj);
	void read_matrix(std::string s);
	Matrix operator+(Matrix& array1) const;
	Matrix operator * ( Matrix& array) const;
	int* operator [](int i) const;
	friend ostream& operator<< (ostream& f, const Matrix& a); // вывод вектора на экран
	Matrix& operator=(const Matrix& a);
	int columns() const;
	int lines() const;
	void reset();

private:
	int _lines;
	int _columns;
	int ** _data;

};
Matrix::Matrix() : _lines(0), _columns(0), _data(nullptr)
{}

Matrix::Matrix(int lines, int columns) : _lines(lines), _columns(columns)
{
	_data = new int*[_lines];
	for (int i = 0; i < _lines; i++)
	{
		_data[i] = new int[_columns];
		for (int j = 0; j < _columns; j++)
		{
			_data[i][j] = rand() % 10;
		}
	}
}

Matrix::Matrix(const Matrix& obj) : _lines(obj._lines), _columns(obj._columns)
{
	_data = new int*[_lines];

	for (int i = 0; i < _lines; i++)
	{
		_data[i] = new int[_columns];
		for (int j = 0; j < _columns; j++)
			_data[i][j] = obj._data[i][j];
	}
}

void Matrix::read_matrix(std::string s)
{
	ifstream fin(s);
	for (int i = 0; i < _lines; i++)
		for (int j = 0; j < _columns; j++)
			fin >> _data[i][j];
	fin.close();

}


int Matrix::columns() const
{
	return(_columns);
}

int Matrix::lines() const
{
	return(_lines);
}
void Matrix::reset()
{
	for (int i = 0; i < _lines; i++)
		for (int j = 0; j < _columns; j++)
			_data[i][j] = 0;
}

Matrix& Matrix::operator=(const Matrix& a)
{
	if (_data)
	{
		for (int i = 0; i < _lines; i++)
			delete _data[i];
		delete[] _data;
	}
	_lines = a._lines;
	_columns = a._columns;
	_data = new int*[_lines];
	for (int i = 0; i < _lines; i++)
	{
		_data[i] = new int[_columns];
		for (int j = 0; j < _columns; j++)
			_data[i][j] = a._data[i][j];

	}
	return (*this);
}

Matrix Matrix::operator+(Matrix& array1) const
{

	Matrix result(*this);
	for (int i = 0; i < _lines; i++)
		for (int j = 0; j < _columns; j++)
			result._data[i][j] += array1._data[i][j];
	return result;
}

Matrix Matrix::operator*(Matrix& array) const
{

	Matrix result(_lines, array.columns());
	result.reset();
	for (int i = 0; i < _lines; i++)
		for (int j = 0; j < array.columns(); j++)
			for (int t = 0; t < _columns; t++)
				result._data[i][j] += _data[i][t] * array._data[t][j];
	return result;
}

int* Matrix::operator [] (int i)
{
	if ((i - 1)<0) exit(0);
	int *temp = new int[_columns];
	for (int j = 0; j < _columns; j++)
		temp[j] = _data[i - 1][j];
	return(temp);

}

ostream& operator<<(ostream& f, const Matrix& a)
{
	for (int i = 0; i < a._lines; i++)
	{
		for (int j = 0; j < a._columns; j++)
		{
			f << a._data[i][j];
			f << " ";
		}
		f << "\n";
	}
	return f;
}
