#include <iostream>
#include <vector>
using namespace std;

bool isValidI(int i,int rows)
{
	return (i > -1 && i < rows);
};
bool isValidJ(int j,int columns)
{
	return (j > -1 && j < columns);
};
//takes input matrix, doing minesweeping calculation based on adjaced edges and
//remember a square in a field can have at most 8 adjacent edges and then tell mines in the output field by printing the output field
vector<char> mineSweeper(const vector<char>& inputMatrix, int row, int col)       
{
	vector<char> outputField(row * col, '0');
	for (int i = 0;i < row;i++)
	{
		for (int j = 0; j < col;j++)
		{
			if (inputMatrix[i *col + j] == '*')
			{
				outputField[i * col + j] = '*';
				if (isValidI(i - 1,row) && inputMatrix[(i - 1) * col + j] != '*')
					outputField[(i - 1) * col + j] += 1;

				if (isValidI(i + 1,row) && inputMatrix[(i + 1) * col + j] != '*')
					outputField[(i + 1) * col + j] += 1;

				if (isValidJ(j + 1,col) && inputMatrix[i * col + (j+1)] != '*')
					outputField[i * col + (j+1)] += 1;

				if (isValidJ(j - 1,col) && inputMatrix[i * col + (j-1)] != '*')
					outputField[i * col + (j-1)] += 1;

				if (isValidI(i + 1,row) && isValidJ(j - 1,col)  && inputMatrix[(i + 1) * col + (j - 1)] != '*')
					outputField[(i + 1) * col + (j-1)] += 1;

				if (isValidI(i - 1,row) && isValidJ(j + 1,col) && inputMatrix[(i - 1) * col + (j + 1)] != '*')
					outputField[(i - 1) * col + (j + 1)] += 1;

				if (isValidI(i + 1,row) && isValidJ(j + 1,col) && inputMatrix[(i + 1) * col + (j + 1)] != '*')
					outputField[(i + 1) * col + (j + 1)] += 1;

				if (isValidI(i - 1,row) && isValidJ(j - 1,col) && inputMatrix[(i - 1) * col + (j - 1)] != '*')
					outputField[(i - 1) * col + (j - 1)] += 1;

			}
		}
	}
	return outputField;
}
void displayField(const vector<char>& field, int row, int col)
{
	for (int i = 0; i < row; i++)           
	{
		for (int j = 0; j < col; j++)
		{
			cout << field[i * col + j];
		}
		cout << "\n";
	}
	cout << "----------------------------------------------------------------------------\n";
}

int main()
{
	vector<char> inputMatrix1 = { '*','*','.','.','.',
							  '.','.','.','.','.',
							  '.','*','.','.','.'
							};
	cout << "Input Matrix\n";
	displayField(inputMatrix1, 3, 5);
	vector<char> outputField = mineSweeper(inputMatrix1, 3, 5);
	displayField(outputField,3,5);

	cout << " Another Example \n";



	 vector<char> inputMatrix2 = { '*','.','.','.',
								   '.','.','.','.',
							       '.','*','.','.',
									'.','.','.','.'
							     };
	 cout << "Input Matrix\n";
	 displayField(inputMatrix2, 4, 4);
	 vector<char> outputField2 = mineSweeper(inputMatrix2, 4, 4);
	 displayField(outputField2, 4, 4);

	return 0;
}


// this code can be further optimized through using direction arrays, 
// which i understood following optimization of code snippet

//vector<char> mineSweeper(const vector<char>& inputMatrix, int row, int col)
//{
//	vector<char> outputField(row * col, '0');
//
//	int dx[8] = { -1, 1, 0, 0,  1, -1,  1, -1 };
//	int dy[8] = { 0, 0, 1,-1, -1,  1,  1, -1 };
//
//	for (int i = 0; i < row; i++)s
//	{
//		for (int j = 0; j < col; j++)
//		{
//			if (inputMatrix[i * col + j] == '*')
//			{
//				outputField[i * col + j] = '*';
//
//				for (int d = 0; d < 8; d++)
//				{
//					int ni = i + dx[d];
//					int nj = j + dy[d];
//
//					if (ni >= 0 && ni < row && nj >= 0 && nj < col)
//					{
//						int idx = ni * col + nj;
//
//						if (inputMatrix[idx] != '*')
//						{
//							outputField[idx] += 1;
//						}
//					}
//				}
//			}
//		}
//	}
//
//	return outputField;
//}
