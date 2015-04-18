//
//  SWToast.h
//  LoginTest
//
//  Created by Stephen Walsh on 30/03/2015.
//  Copyright (c) 2015 Stephen Walsh. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SWPlainToastDelegate <NSObject>

- (void)actionButtonTapped;

@end

@protocol SWLoginToastDelegate <NSObject>

- (void)loginButtonTappedWithUsername:(NSString*)username
                          andPassword:(NSString*)password;
- (void)forgotPasswordButtonTapped;

@end

@protocol SWForgotPasswordDelegate <NSObject>

- (void)resetButtonTappedWithUsername:(NSString*)username;

@end

typedef NS_ENUM(NSInteger, SWBufferedToastType) {
    SWBufferedToastTypePlain,
    SWBufferedToastTypeLogin,
    SWBufferedToastTypeNotice,
    SWBufferedToastTypeForgotPassword
};

@interface SWToast : UIView <UITextFieldDelegate>

@property (nonatomic, assign) SWBufferedToastType toastType;
@property (nonatomic, assign) BOOL isLoading;
@property (nonatomic, readonly) BOOL loadingBlocksDismiss;
@property (nonatomic, weak) id <SWPlainToastDelegate> plainToastDelegate;
@property (nonatomic, weak) id <SWLoginToastDelegate> loginToastDelegate;
@property (nonatomic, weak) id <SWForgotPasswordDelegate> forgotPasswordToastDelegate;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *subtitleLabel;
@property (nonatomic, strong) UIButton *actionButton;
@property (nonatomic, strong) UIButton *forgotPasswordButton;
@property (nonatomic, strong) UITextField *usernameField;
@property (nonatomic, strong) UITextField *passwordField;

- (instancetype)initPlainToastWithColour:(UIColor*)color
                                   title:(NSString*)title
                                subtitle:(NSString*)subtitle
                             actionTitle:(NSString*)actionTitle
                     animationImageNames:(NSArray*)animationImageNames
                                plainDelegate:(id)delegate
                               andParent:(UIView*)parentView;

- (instancetype)initLoginToastWithColour:(UIColor*)color
                                   title:(NSString*)title
                           usernameTitle:(NSString*)usernameTitle
                           passwordTitle:(NSString*)passwordTitle
                               doneTitle:(NSString*)doneTitle
                     animationImageNames:(NSArray*)animationImageNames
                           loginDelegate:(id)loginDelegate
                               andParent:(UIView*)parentView;


- (instancetype)initForgotPasswordToastWithColour:(UIColor*)color
                                   title:(NSString*)title
                           usernameTitle:(NSString*)usernameTitle
                               doneTitle:(NSString*)doneTitle
                     animationImageNames:(NSArray*)animationImageNames
                           loginDelegate:(id)forgotPasswordDelegate
                               andParent:(UIView*)parentView;

- (instancetype)initNoticeToastWithColour:(UIColor*)color
                                    title:(NSString*)title
                                 subtitle:(NSString*)subtitle
                      animationImageNames:(NSArray*)animationImageNames
                                andParent:(UIView*)parentView;

- (void)appear;
- (void)disappear;
- (void)showBuffer;
- (void)hideBuffer;

@end
