

To change the URL schemes of all pages of Chromium like from chrome://settings to xyz://settings, you can follow these steps:



Open the Chromium source code.

Find the file chrome/browser/resources/chrome\_urls.cc.

In this file, find the section that starts with // Chrome URLs.

Inside this section, find the line that starts with const char\* kChromeScheme = "chrome";.

Change the value of kChromeScheme to xyz.

Save the file.

Restart Chromium.

Once you have completed these steps, all of the Chromium pages will use the xyz:// scheme instead of the chrome:// scheme.



Here are some additional details about the code that you need to change:



The const char\* kChromeScheme = "chrome"; line defines the chrome:// scheme.

The chrome:// scheme is used for all of the Chromium pages.

By changing the value of kChromeScheme, you can change the scheme that is used for all of the Chromium pages.

For more information, you can refer to the Chromium source code documentation.



Here are some additional steps that you can take to make the change more permanent:



Create a new file called chrome-urls.h in the chrome/browser/resources directory.

In this file, add the following code:

Code snippet

\#ifndef CHROME\_BROWSER\_RESOURCES\_CHROME\_URLS\_H\_

\#define CHROME\_BROWSER\_RESOURCES\_CHROME\_URLS\_H\_



const char\* kChromeScheme = "xyz";



\#endif  // CHROME\_BROWSER\_RESOURCES\_CHROME\_URLS\_H\_

Use code with caution. Learn more

In the chrome/browser/resources/chrome\_urls.cc file, add the following line to the top of the file:

Code snippet

\#include "chrome/browser/resources/chrome-urls.h"

Use code with caution. Learn more

Save the files.

Restart Chromium.

Once you have completed these steps, the change to the URL scheme will be permanent.

