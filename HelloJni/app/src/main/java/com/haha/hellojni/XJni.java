package com.haha.hellojni;

import android.widget.Toast;

public class XJni {

    static {
        System.loadLibrary("xjni");
    }

    public native String getStr(String s, int len);

    public native void displayHelloWorld();

    // 提供由JNI调用
    public void showToast(String msg) {
        Toast.makeText(MainApplication.getInstance(), msg, Toast.LENGTH_SHORT).show();
    }

    // 提供由JNI调用
    public void showToast() {
        Toast.makeText(MainApplication.getInstance(), "hello from jni", Toast.LENGTH_SHORT).show();
    }

    // 提供由JNI调用
    public void showToast(int k) {
        Toast.makeText(MainApplication.getInstance(), "hello from jni : " + k, Toast.LENGTH_SHORT).show();
    }

}