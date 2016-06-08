//

#include <vector>

using namespace std;

int totalNQueens(int n) {
	if(n == 1)
		return 1;

	if(n <= 3)
		return 0;

	vector<char> board(n, vector<char>(n, '.'));
	
}
