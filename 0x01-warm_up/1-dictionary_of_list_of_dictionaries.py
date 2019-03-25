#!/usr/bin/python3
"""Makes GET request to REST API to export data of all tasks from all employees
in JSON format."""
import json
import requests

if __name__ == '__main__':
    users = {}
    data = requests.get('https://jsonplaceholder.typicode.com/users').json()
    for user in data:
        users[user['id']] = user['name']

    filename = 'todo_all_employees.json'
    all_todos = {}
    data = requests.get('https://jsonplaceholder.typicode.com/todos').json()
    for todo in data:
        userId = todo['userId']
        if userId not in all_todos:
            all_todos[userId] = []
        task = {'username': users[userId],
                'task': todo['title'],
                'completed': todo['completed']}
        all_todos[userId].append(task)
    with open(filename, 'w') as f:
        json.dump(all_todos, f)
