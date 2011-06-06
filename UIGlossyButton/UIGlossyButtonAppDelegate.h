//
//  UIGlossyButtonAppDelegate.h
//  UIGlossyButton
//
//  Created by Water Lou on 06/06/2011.
//  Copyright 2011 First Water Tech Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TestButtonViewController;

@interface UIGlossyButtonAppDelegate : NSObject <UIApplicationDelegate> {

}

@property (nonatomic, retain) IBOutlet UIWindow *window;

@property (nonatomic, retain) IBOutlet TestButtonViewController *viewController;

@end
