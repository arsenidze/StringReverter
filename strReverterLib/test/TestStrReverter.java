import strReverter.StrReverter;

class TestStrReverter {
    private static void fillStrAndReverse(char[] str, char[] reverse, int len)
    {
        for (int i = 0; i < len; ++i)
        {
            str[i] = (char)(32 + (int) (Math.random() * (127 - 32)));
            reverse[len - 1 - i] = str[i];        
        }
        str[len] = '\0';
        reverse[len] = '\0';
    }

    private static void testStep(String in, String out) {
        String  out_real;
        boolean status;

        status = StrReverter.Write(in);
        System.out.printf("status: %b\n", status);
        out_real = StrReverter.Read();
        System.out.printf("in:         %s\n", in);
        System.out.printf("out_real:   %s\n", out_real);

        System.out.printf("\n\n");
    }

    private static final int NTESTS = 50;

 	public static void main(String[] args) {
        new StrReverter();
        String  in;
        String  out;
        int     len;

        in = null;
        out = null;
        testStep(in, out);

        in = "123456789";
        out = "987654321";
        testStep(in, out);

        in = "123456789";
        out = "987654321";
        testStep(in, out);

        in = "123456789";
        out = "987654321";
        testStep(in, out);

        in = "12345678912345qwert";
        out = "trewq54321987654321";
        testStep(in, out);

        for (int i = 0; i < NTESTS; ++i)
        {
            len = (int)(Math.random() * 50);
            System.out.printf("Test number: %d\n", i);
            char[] str = new char[len + 1];
            char[] reverse = new char[len + 1];
            fillStrAndReverse(str, reverse, len);
            testStep(new String(str), new String(reverse));
        }
    }
}