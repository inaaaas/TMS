#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include "User.h"
#include "Task.h"
class TaskManager {
    std::vector<User*> m_users;
    std::vector<Task*> m_all_tasks;
public:
    User* loggedInUser;
    TaskManager(const TaskManager& other); 
    TaskManager(TaskManager&& other) noexcept; 
    ~TaskManager();
    //User Management
    void registerUser(const User& user);
    User* login(const std::string& username, const std::string& password); 
    void logout(User* user); 
    //Task Management
    void addTaskForUser(const Task& task);
    void deleteTaskForUser(const std::string& title);
    void editTaskForUser(const std::string& title, const Task& updatedTask);
    void displayTasksForUser() const; 
};
#endif