#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Content {
public:
    virtual ~Content() {}
    virtual std::string text() const = 0;
};

class ThanksContent : public Content {
public:
    std::string text() const override {
        return "谢谢参与";
    }
};

class NoHomeworkContent : public Content {
public:
    std::string text() const override {
        return "免当天作业一次";
    }
};

class ReciteContent : public Content {
public:
    std::string text() const override {
        return "背诵课文";
    }
};

class CopyPoemContent : public Content {
public:
    std::string text() const override {
        return "抄写唐诗10首";
    }
};

class Panel {
public:
    explicit Panel(std::unique_ptr<Content> content)
        : mContent(std::move(content)) {}

    void show() const {
        std::cout << mContent->text() << std::endl;
    }

private:
    std::unique_ptr<Content> mContent;
};

class Board {
public:
    void addPanel(std::unique_ptr<Panel> panel) {
        mPanels.push_back(std::move(panel));
    }

    void choose(std::size_t index) const {
        if (index >= mPanels.size()) {
            std::cout << "无效抽奖条" << std::endl;
            return;
        }

        mPanels[index]->show();
    }

private:
    std::vector<std::unique_ptr<Panel> > mPanels;
};

int main() {
    Board board;

    board.addPanel(std::unique_ptr<Panel>(new Panel(std::unique_ptr<Content>(new ThanksContent))));
    board.addPanel(std::unique_ptr<Panel>(new Panel(std::unique_ptr<Content>(new NoHomeworkContent))));
    board.addPanel(std::unique_ptr<Panel>(new Panel(std::unique_ptr<Content>(new ReciteContent))));
    board.addPanel(std::unique_ptr<Panel>(new Panel(std::unique_ptr<Content>(new CopyPoemContent))));

    std::cout << "选择第1个抽奖条：" << std::endl;
    board.choose(0);

    std::cout << "选择第2个抽奖条：" << std::endl;
    board.choose(1);

    std::cout << "选择第4个抽奖条：" << std::endl;
    board.choose(3);

    return 0;
}
