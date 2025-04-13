
#include <iostream>
#include <string>

using namespace std;

class IButton
{
public:
   virtual void press() = 0;
};

class ITextBox
{
public:
   virtual void setetxt() = 0;
};

class MacButton : public IButton
{
public:
   void press()
   {
      std::cout << "mac button created" << std::endl;
   }
};

class WinButton : public IButton
{
public:
   void press()
   {
      std::cout << "Win button created" << std::endl;
   }
};

class MacTextBox : public ITextBox
{
public:
   void setetxt()
   {
      std::cout << "mac TextBox created" << std::endl;
   }
};

class WinTextBox : public ITextBox
{
public:
   void setetxt()
   {
      std::cout << "win TextBox created" << std::endl;
   }
};

class GUIFactory
{
public:
   virtual ~GUIFactory() {}
   virtual IButton *createButton() = 0;
   virtual ITextBox *createTextBox() = 0;
};

class MacFactory : public GUIFactory
{
public:
   IButton *createButton()
   {
      return new MacButton();
   }
   ITextBox *createTextBox()
   {
      return new MacTextBox();
   }
};

class WinFactory : public GUIFactory
{
public:
public:
   IButton *createButton()
   {
      return new WinButton();
   }
   ITextBox *createTextBox()
   {
      return new WinTextBox();
   }
};

class GUIAbstractFactory
{
public:
   static GUIFactory *createFactory(string osType)
   {
      if (osType == "Mac")
      {
         return new MacFactory();
      }
      else if (osType == "Win")
      {
         return new WinFactory();
      }
      return nullptr;
   }
};

int main()
{
   string osType;
   cin >> osType;

   GUIFactory *element = GUIAbstractFactory::createFactory(osType);
   IButton *button = element->createButton();
   button->press();
   ITextBox *textBox = element->createTextBox();
   textBox->setetxt();
}
