function :
	1）提示输入行数rows和列数cols;
	2）一个带有边框（*）的rows*cols矩形。
 下面是rows=6 cols=16的输出
 ****************
 *              *
 *              *
 *              *
 *              *
 ****************

Analysis:
  把这个图形分成两个部分，分别是边界和内部。
边界上是"*"，内部是" "。
输出时，采用两重循环，当碰到边界时输出"*"，
否则输出" "。

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Please frame size (rows,cols): " << endl;
	int rows, cols;
	cin >> rows >> cols;
	for(int row_i=0; row_i<rows; row_i++)
	{
		for(int col_j=0; col_j<cols; col_j++)
		{
			if( col_j==0 || row_i==0 || row_i==rows-1 || col_j==cols-1 )
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}