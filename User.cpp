#include <iostream>
#include "User.h"

User::User(const std::string id, const std::string& username, const std::string& password) {
    m_id = id;
    m_username = username;
    m_password = password;
    is_logged = false;
}

User::User(const User& other) {
    this -> m_id = other.m_id;
    this -> m_password = other.m_password;
    this -> m_username = other.m_username;
    this -> is_logged = other.is_logged;
    for (const auto& task : other.m_tasks) {
        this -> m_tasks.push_back(new Task(*task));
    }
}

User::User(User&& other) noexcept {
    this -> m_id = other.m_id;
    this -> m_password = other.m_password;
    this -> m_username = other.m_username;
    this -> is_logged = other.is_logged;
    this ->m_tasks = other.m_tasks;
    other.m_tasks.clear();
}

User::~User() {
    for (Task* task : m_tasks) {
        delete task;
    }
}

void User::addTask(Task* task) {
    this -> m_tasks.push_back(task);
}

void User::deleteTask(const std::string& title) {
    for (auto task = m_tasks.begin(); task != m_tasks.end(); ++task) {
        if ((*task) -> getTitle() == title) {
            delete *task;
            m_tasks.erase(task);
            std::cout << "Task deleted: " << title << std::endl;
            return;
        }
    }
    std::cout << "Task not found: " << title << std::endl;
}
    
    void User::editTask(const std::string& title, const Task& updatedTask) {
        for (auto task : m_tasks) {
            if (task -> getTitle() == title) {
                *task = updatedTask;
                break;
            }
        }
    }
    void User::listTasks() const {
        for (auto task : m_tasks) {
            std::cout << *task << std::endl;
        }
    }
    Task* User::searchTask(const std::string& title) {
        for (auto task : m_tasks) {
            if (task -> getTitle() == title) {
                return task;
            }
        }
        return nullptr;
    }
    
    bool User::login(const std::string& passwd) {
        if (passwd == m_password) {
            is_logged = true;
            return true;
        }
        return false;
    }
    void User::logout() {
        is_logged = false;
    }
    User::operator bool() const {
        return is_logged;
    }
    User& User::operator=(const User& other) {
        if (this == &other) {
            return *this;
        }
        m_id = other.m_id;
        m_password = other.m_password;
        m_username = other.m_username;
        is_logged = other.is_logged;
        for (auto task : m_tasks) {
            delete task;
        }
        m_tasks.clear();
        for (auto task : other.m_tasks) {
            m_tasks.push_back(new Task(*task));
        }
        return *this;
    }
    User& User::operator=(User&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        m_id = std::move(other.m_id);
        m_username = std::move(other.m_username);
        m_password = std::move(other.m_password);
        m_tasks = std::move(other.m_tasks);
        is_logged = other.is_logged;
        return *this;
    }
