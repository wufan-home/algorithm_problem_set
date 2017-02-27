/*
 * Write a program that outputs the string representation of numbers from 1 to n. 
 * But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”.
 * For numbers which are multiples of both three and five output “FizzBuzz”.
 * Example:
 * n = 15,
 * Return: ["1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"]
 *
 * Solution: The solution is straightforward. 
 * The only thing needs to take care here is the order of appending strings to the output.
 * String "Fizz" should be before the "Buzz", since we have an output "FizzBuzz" when the number is 15.
 * This avoid us to check the number to be divisible by 15.
 */

vector<string> fizzBuzz(int n) {
        vector<string> outputs;
        for(int i = 1; i <= n; ++i)
        {
            string output = "";
            if(i % 3 == 0)
                output.append("Fizz");
                
            if(i % 5 == 0)
                output.append("Buzz"); 
                
            if(output.empty())
                output = to_string(i);
                
            outputs.push_back(output);
        }
        
        return outputs;
    }
