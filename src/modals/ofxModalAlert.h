/*
    Copyright (C) 2016 Stephen Braitsch [http://braitsch.io]

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma once
#include "ofxModalWindow.h"

class ofxModalAlert : public ofxModalWindow {

    public:

        ofxModalAlert()
        {
            addButton("ok");
            setTheme(mTheme);
            setTitle("alert");
            setMessage("This is an alert message!");
        }
    
        void draw()
        {

        }
    
        void update()
        {

        }
    
        void setTheme(std::shared_ptr<ofxModalTheme> theme)
        {
            ofxModalWindow::setTheme(theme);
            ofxDatGuiButton* b1 = getButton("ok");
            b1->setWidth(theme->layout.button.width);
            b1->setLabelColor(theme->color.button.wireframe.label);
            b1->setBackgroundColors(theme->color.button.wireframe.background,
                theme->color.button.wireframe.backgroundOnMouseOver,
                theme->color.button.wireframe.backgroundOnMouseDown);
            if (theme->layout.button.borders) {
                b1->setBorder(theme->color.button.wireframe.border, 1);
            }
        }
    
    private:
    
        void onButtonEvent(ofxDatGuiButtonEvent e)
        {
            hide();
            if (e.target == getButton("ok")){
                dispatchCallbacks(ofxModalEvent::CONFIRM);
            }
        }

};


