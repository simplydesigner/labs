
#include "stdafx.h" 
#include <iostream> 
#include <stdio.h> 
#include <string> 
#include <conio.h> 
#include <windows.h> 
#include <stdlib.h> 
#include <fstream> 
using namespace std;
class Matrix
{
private:
	int lines;
	int columns;
	int **mas;
public:
	Matrix();
	Matrix(int _lines, int _columns);
	void read_matrix(std::string s);
	void print_matrix();
	Matrix operator + (Matrix array);
	Matrix operator * (Matrix array);
	int* operator [](int i);
	int get_cout_columns();
	int get_cout_lines();
	void reset();

};
Matrix::Matrix()
{
	lines = 0;
	columns = 0;
	mas = new int*[0];
	mas[0] = new int[0];

};
Matrix::Matrix(int _lines, int _columns)
{
	lines = _lines;
	columns = _columns;
	mas = new int*[lines];
	for (int i = 0; i < lines; i++)
	{
		mas[i] = new int[columns];
	}

}

void Matrix::read_matrix(std::string s)
{
	ifstream fin(s);
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			fin >> mas[i][j];
	fin.close();

}
void Matrix::print_matrix()
{
	for (int i = 0; i < lines; i++) {

		for (int j = 0; j < columns; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
}
Matrix Matrix::operator + (Matrix array)
{

	Matrix result(*this);
	for (int i = 0; i < result.lines; i++)
		for (int j = 0; j < result.columns; j++)
			result.mas[i][j] += array.mas[i][j];
	return(result);
}

Matrix Matrix::operator * (Matrix array)
{

	Matrix result(lines, array.get_cout_columns());
	result.reset();
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < array.get_cout_lines(); j++)
			for (int t = 0; t < columns; t++)
				result.mas[i][j] += mas[i][t] * array.mas[t][j];
	return result;
}

int* Matrix::operator [] (int i)
{
	if ((i - 1)<0) exit(0);
	int *temp = new int[columns];
	for (int j = 0; j < columns; j++)
		temp[j] = mas[i - 1][j];
	return(temp);

}
int Matrix::get_cout_columns()
{
	return(columns);


}

int Matrix::get_cout_lines()
{
	return(lines);
}
void Matrix::reset()
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			mas[i][j] = 0;
}
int main(void)
{
	Matrix matrix(5, 5);
	Matrix matrix1(5, 5), matrix2(5, 5);
	cout << "Write way of file '*.txt' " << endl;
	std::string s;
	std::getline(std::cin, s);
	cout << "You wrote " << s << endl;
	matrix.read_matrix(s);
	matrix2.read_matrix(s);
	matrix.print_matrix();
	int *line_matrix;
	line_matrix = matrix[2];
	for (int i = 0; i < matrix.get_cout_columns(); i++)
		cout << line_matrix[i] << " ";

	cout << endl;
	matrix1 = matrix*matrix;
	matrix1.print_matrix();

	system("pause");


}
