﻿#include "AppDelegate.h"
#include "GameMenu.h"
#include "Config.h"
#include "SimpleAudioEngine.h"
#include "HttpClient.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
    cocos2d::network::HttpClient::destroyInstance();
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::createWithRect("ChineseChessCC", Rect(0, 0, 800, 640), 1);
        director->setOpenGLView(glview);
    }
    glview->setDesignResolutionSize(800, 640, ResolutionPolicy::SHOW_ALL);

    // turn on display FPS
    //director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    Config::init();
    FileUtils::getInstance()->addSearchResolutionsOrder("fonts");

    // create a scene. it's an autorelease object
    auto scene = GameMenu::scene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
