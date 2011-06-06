//
//  UIView+ExtraAnimation.h
//
//  Created by Water Lou on 15/09/2010.
//  Copyright 2010 First Water Tech Ltd. All rights reserved.
// 
//  many visual effects and animation effects create using CoreAnimation and CALayer
//

#import <Foundation/Foundation.h>

@interface UIView(LayerEffects)

// set round corner
- (void) setCornerRadius : (CGFloat) radius;
// set inner border
- (void) setBorder : (UIColor *) color width : (CGFloat) width;
// set the shadow
// Example: [view setShadow:[UIColor blackColor] opacity:0.5 offset:CGSizeMake(1.0, 1.0) blueRadius:3.0];
- (void) setShadow : (UIColor *)color opacity:(CGFloat)opacity offset:(CGSize) offset blurRadius:(CGFloat)blurRadius;

@end
