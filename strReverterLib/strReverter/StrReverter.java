package strReverter;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Platform;

public class StrReverter {

    private static String LIBRARY_LOCATION = "libstr_reverter.so";

    private interface CLibrary extends Library {
        CLibrary INSTANCE = Native.load(LIBRARY_LOCATION, CLibrary.class);

        boolean Write(String str);
        String  Read();
    }

    public static boolean Write(String str) {
        return (CLibrary.INSTANCE.Write(str));
    }

    public static String Read() {
        return (CLibrary.INSTANCE.Read());
    }
}