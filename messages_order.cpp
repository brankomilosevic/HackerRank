/*
HACKERRANK: Messages Order
https://www.hackerrank.com/challenges/messages-order
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
public: 
    static int id;
    Message() 
    {
        ++id; 
        msg_id_ = id;
    }
    Message(string s) : data_ {s} 
    {
        ++id;
        msg_id_ = id;
    }
    const string& get_text() 
    {
        return data_;
    }
    const int get_msg_id() 
    {
        return msg_id_;
    }
        bool operator < (Message &B)
    {
        return msg_id_ < B.get_msg_id();
    }
private:
    string data_;
    int msg_id_;
};

int Message::id = 0;

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) 
    {
        return Message(text);
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
