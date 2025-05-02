#include <iostream>

using namespace std;

// Command Interface
class ActionListenerCommand
{
public:
    virtual void execute() = 0;
    virtual ~ActionListenerCommand() {}
};

// receiver
class Document
{
public:
    void save()
    {
        cout << " Document saved " << endl;
    }

    void open()
    {
        cout << " Document opened" << endl;
    }
};

// Concrete Command
class ActionOpen : public ActionListenerCommand
{
private:
    Document *doc;

public:
    ActionOpen(Document *document) : doc(document) {}
    void execute()
    {
        doc->open();
    }
};

class ActionSave : public ActionListenerCommand
{
private:
    Document *doc;

public:
    ActionSave (Document* document) : doc(document){}
      void execute() {
        doc->save();
      }
};

// Invoker
class MenuOptions
{
private:
    vector<ActionListenerCommand *> commands;

public:
    void addCommands(ActionListenerCommand *command)
    {
        commands.push_back(command);
    }

    void executeCommands()
    {
        for (auto cmd : commands)
        {
            cmd->execute();
        }
    }
};

int main()
{
    Document doc;
    MenuOptions menu;

    ActionListenerCommand *clickOpen = new ActionOpen(&doc);
    ActionListenerCommand *clickSave = new ActionSave(&doc);

    menu.addCommands(clickOpen);
    menu.addCommands(clickSave);

    menu.executeCommands();

    delete clickOpen;
    delete clickSave;

    return 0;
}
