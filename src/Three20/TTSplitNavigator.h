//
// Copyright 2009-2010 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#if __IPHONE_3_2 <= __IPHONE_OS_VERSION_MAX_ALLOWED

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class TTNavigator;
@class TTURLMap;
@protocol TTNavigatorDelegate;

/**
 * Enumeration of the split view sides. For use with [TTNavigator navigatorAtIndex:]
 */
typedef enum {
  TTNavigatorSplitViewInvalid   = -1, // Not in a split view.
  TTNavigatorSplitViewBegin     = 0,
  TTNavigatorSplitViewLeftSide  = 0,  // In a split view, the left-side navigator
  TTNavigatorSplitViewRightSide,      // In a split view, the right-side navigator
  TTNavigatorSplitViewEnd
} TTNavigatorSplitView;


/**
 * A split view navigator designed for the iPad. This navigator contains two proper TTNavigator
 * objects, one for the left and right sides of the split view.
 */
@interface TTSplitNavigator : NSObject {
  id<TTNavigatorDelegate> _delegate;
  
  TTURLMap*               _URLMap;
  
  UIWindow*               _window;
  UISplitViewController*  _rootViewController;

  NSArray*                _navigators;
}

/**
 * Access the single global split navigator. Use this navigator if your app wishes to use a split
 * view controller.
 */
+ (TTSplitNavigator*)splitNavigator;

/**
 * Access the TTNavigator corresponding to a given side of a split view controller.
 * The indices map directly to the indices of a split view controller. Index 0 maps to the left
 * view controller. Index 1 maps to the right view controller.
 */
- (TTNavigator*)navigatorAtIndex:(TTNavigatorSplitView)index;

/**
 * The URL map used to translate between URLs and view controllers.
 *
 * TODO: Document this with respect to what it means for a TTSplitNavigator.
 *
 * @see TTURLMap
 */
@property(nonatomic,readonly) TTURLMap* URLMap;

/**
 * The window that contains the view controller hierarchy.
 *
 * By default retrieves the keyWindow. If there is no keyWindow, creates a new
 * TTSplitNavigatorWindow.
 */
@property(nonatomic,retain) UIWindow* window;

/**
 * The controller that is at the root of the view controller hierarchy, always a split view
 * controller.
 */
@property(nonatomic,readonly) UISplitViewController* rootViewController;

@end

#endif
