//
//  Crash.m
//  sample
//
//  Created by cocos2dx on 14-11-10.
//  Copyright (c) 2014年 cocos2dx. All rights reserved.
//

#include "Crash.h"
#include <jni.h>
#include <android/log.h>
#include "PluginJniHelper.h"
extern "C"{

void Java_com_anysdk_sample_wrapper_nativeReportException(JNIEnv*  env, jobject thiz)
{
	Crash::getInstance()->reportException();
}

void Java_com_anysdk_sample_wrapper_nativeSetUserIdentifier(JNIEnv*  env, jobject thiz)
{
	Crash::getInstance()->setUserIdentifier();
}

void Java_com_anysdk_sample_wrapper_nativeLeaveBreadcrumb(JNIEnv*  env, jobject thiz)
{
	Crash::getInstance()->leaveBreadcrumb();
}
}

Crash* Crash::_pInstance = NULL;

Crash::Crash()
{
//    setListener();
}

Crash::~Crash()
{
    
}

Crash* Crash::getInstance()
{
    if (_pInstance == NULL) {
        _pInstance = new Crash();
        _pInstance->_Crash = AgentManager::getInstance()->getCrashPlugin();
    }
    return _pInstance;
}

void Crash::purge()
{
    if (_pInstance)
    {
        delete _pInstance;
        _pInstance = NULL;
    }
}

//设置用户唯一标示符
void Crash::setUserIdentifier()
{
    if(_Crash)
    {
        _Crash->setUserIdentifier("AnySDK");
    }
    
}

//手动上报Exception
void Crash::reportException()
{
    if(_Crash)
    {
        _Crash->reportException("message", "exception");
        string message = NULL;
        message.size();
    }
    
}

//设置面包屑
void Crash::leaveBreadcrumb()
{
    if(_Crash)
    {
        _Crash->leaveBreadcrumb("bread");
    }
    
}



