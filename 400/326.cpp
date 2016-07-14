/*
  Given an integer, write a function to determine if it is a power of three.
*/

bool isPowerOfThree(int n) {
	double error = 0.000000000001;
        
        double upper = log10(n);
        double lower = log10(3);
        double quo = upper / lower;
        
        return (fabs(quo - int(quo)) < error);
}
