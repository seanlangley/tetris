#ifndef DEBUG_H
#define DEBUG_H
#include <string>
#include <ncurses.h>

class DebugMsg {
public:
    DebugMsg(unsigned y, unsigned x, std::string msg)
        :y(y), x(x), msg(msg){
    }
    unsigned get_y(){
        return y;
    }
    unsigned get_x(){
        return x;
    }
    std::string get_msg(){
        return msg;
    }
private:
    unsigned y,x;
    std::string msg;
};

class DebugMsgQueue{
public:
    DebugMsgQueue(unsigned y, unsigned x){
        debug_y = y;
        debug_x = x;
    }
    void MakeDebugMsg(std::string msg){
        DebugMsg new_msg = DebugMsg(debug_y, debug_x, msg);
        m_messages.push_back(new_msg);
        debug_y += 1;
    }
    void PrintDebugMessages() {
        std::vector<DebugMsg>::iterator it = m_messages.begin();
        for(; it != m_messages.end(); it++){
            mvprintw(it->get_y(), it->get_x(), it->get_msg().c_str());
        }
    }
    void UpdateDebugMsg(int idx, std::string msg){
        DebugMsg new_msg = DebugMsg(m_messages[idx].get_y(), 
                           m_messages[idx].get_x(), msg);
        m_messages[idx] = new_msg;
    }
    unsigned size(){
        return m_messages.size();
    }
private:
    unsigned debug_y, debug_x;
    std::vector<DebugMsg> m_messages;
};

#endif