package csu.tliu.ndk.media;

public class Test {
    static {
        System.loadLibrary("fmedia");
    }

    public static native String get();
}
