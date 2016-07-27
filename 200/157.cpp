/*

*/

int read(char *buf, int n) {
	int actual = read4(buf);
	for(int cur = actual; cur == 4 && actual < n;)
	{
		cur = read4(buf + actual);
		actual += cur;
	}
	return min(actual, n);
}
