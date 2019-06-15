#include <jni.h>
#include <string>


extern "C"
JNIEXPORT jstring JNICALL
Java_com_haha_hellojni_XJni_getStr(JNIEnv *env, jobject instance, jstring s_, jint len) {

    const char *s = env->GetStringUTFChars(s_, 0);

    char *newChars = NULL;
    newChars = (char *) malloc(len + 1);

    int i = 0;
    //2:给C语言字符减1
    for (i = 0; i < len; i++) {
        newChars[i] = s[i] + 1;
    }
    env->ReleaseStringUTFChars(s_, s);
    return env->NewStringUTF(newChars);
}


extern "C"
JNIEXPORT void JNICALL
Java_com_haha_hellojni_XJni_displayHelloWorld(JNIEnv *env, jobject instance) {
    char param[]="中文你好，i want to call callFromJNI3.";
    jclass clz = env->GetObjectClass(instance);
    jmethodID showToastMethod = env->GetMethodID(clz, "showToast", "(Ljava/lang/String;)V");
    env->CallVoidMethod(instance, showToastMethod, env->NewStringUTF(param));
}