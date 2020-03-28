package csu.tliu.ndk.media;

public class FfmpegAudioPlayer {
    static {
        System.loadLibrary("fmedia");
    }

    public FfmpegAudioPlayer() {
        nativePtr = native_init();
    }

    private long nativePtr;

    public void prepare(OnPrepaerListener listener) {
        native_prepaer(nativePtr, listener);
    }


    private native void native_prepaer(long nativePtr, OnPrepaerListener listener);
    private native long native_init();
}
