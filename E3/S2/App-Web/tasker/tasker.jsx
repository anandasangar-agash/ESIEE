import * as React from 'react';
import * as ReactDOM from 'react-dom/client';


async function fetchTask(cle, setTasks){
    const response = await fetch(`/api/task/${encodeURIComponent(cle)}`, {method: "GET"});
    if(!response.ok){
        throw new Error();
    }
    const data = await response.json();
    setTasks(data);
}

async function deleteTask(id, tasks, setTasks){
    const response = await fetch(`/api/task/${encodeURIComponent(id)}`, {method: "DELETE"});
    if(!response.ok){
        throw new Error();
    }
    const filteredTasks = tasks.filter(i => i.id !== id);
    setTasks(filteredTasks);
}

async function fetchPut(id, updateTask, tasks, setTasks){
    const response = await fetch(`/api/task/${encodeURIComponent(id)}`, {
        method: "PUT",
        headers: {
            'Content-Type' : 'application/json',
            'Accept' : 'application/json'
        },
        body: JSON.stringify(updateTask)
    });
    if(!response.ok){
        throw new Error();
    }
    const updateTasks = tasks.map(t => t.id === updateTask.id ? t = updateTask : t);
    setTasks(updateTasks);
}


function TaskList({cle}){

    const [tasks, setTasks] = React.useState([]);
    React.useEffect(() => {fetchTask(cle,setTasks);}, []);

    return <>
    <SelectBar cle={cle} setTasks={setTasks} />
    <div className='tasklist'>
        {tasks.map(task => <TaskItem key={task.id} task={task} tasks={tasks} setTasks={setTasks} /> )}
    </div>
    </>
}

function SelectBar({cle, setTasks}){

    return <>
    Sort by <select defaultValue={cle} onChange={async (e) => {const key = e.target.value; await fetchTask(key, setTasks)}}>
        <option value="id">id</option>
        <option value="title">title</option>
        <option value="author">author</option>
    </select>
    </>
}

function DeleteButton({id, tasks, setTasks}){

    return <>
        <button onClick={async () => await deleteTask(id, tasks, setTasks)}>X</button> Task : {id}
    </>
}

function TaskItem({task, tasks, setTasks}){

    const {id, title, author, tags, text} = task;

    return <>
    <div className='task'>
        <div className='taskleft'>
            <div>
                <DeleteButton id={id} tasks={tasks} setTasks={setTasks} />
            </div>
            <div className='tasktitle'>{title}</div>
            <div>Author : {author}</div>
            <div>Tags : {tags.join(", ")}</div>
        </div>
        <div className='taskright'>
            <textarea value={text} onChange={async (e) => {
                const updateTask = {...task, text: e.target.value };
                await fetchPut(id, updateTask, tasks, setTasks);}}></textarea>
        </div>
    </div>
    </>
}

function App() {
    let tasks = [
        { id: "1", title: "Upcoming campaign", author: "Jane", tags : ["marketing"], text: "Call John"},
        { id: "2", title: "Approve use of ChatGPT", author: "Sama", tags : ["legal", "hr"], text: "Are we in trouble ?"},
        { id: "3", title: "New Design !", author:"Jean", tags: ["marketing"], text: "What do you think about the new design ?"}
    ];

    const key = "title";
    return <>
        <h1>Tasker</h1>
        <TaskList cle={key}/>
    </>;
}

window.onload = () => {
    let appDOM = document.getElementById("App");
    let root = ReactDOM.createRoot(appDOM);
    root.render(<App/>);
};