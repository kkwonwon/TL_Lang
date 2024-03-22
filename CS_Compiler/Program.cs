using Analysis;
using Define;

class Program
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Hello, World!");

        List<Token> tokenList = Scan.ScanToken(args);
    }
}
