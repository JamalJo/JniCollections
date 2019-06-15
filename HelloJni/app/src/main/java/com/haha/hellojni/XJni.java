package com.haha.hellojni;

public class XJni {

    static {
        System.loadLibrary("xjni");
    }

    public native String getStr(String s, int len);
}