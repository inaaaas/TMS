#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "Task.h"

class User {
    std::string m_id;
    std::string m_username;
    std::string m_password;
    std::vector<Task*> m_tasks;
    bool is_logged;
public:
    User(const std::string id, const std::string& username, const std::string& password);
    User(const User& other);
    User(User&& other) noexcept;
    ~User();

    void addTask(Task* task);
    void deleteTask(const std::string& title);
    void editTask(const std::string& title, const Task& updatedTask);
    void listTasks() const;
    Task* searchTask(const std::string& title);
    
    bool login(const std::string& passwd);
    void logout();

    User& operator=(const User& other);
    User& operator=(User&& other) noexcept;

    operator bool() const;
};
#endif