import java.util.HashMap;
import java.util.Map;

public class TaskService{
  private static TaskService instance;
  private Map<String, Task> tasks;
  private int taskId;
  
  private TaskService(){
    tasks = new HashMap<>();
  }
  
  public static TaskService getInstance(){
    if(instance == null){
      instance = new TaskService();
    }
    return instance; 
  }
  
  public String generateTaskId(){
    taskId++;
    String formatString = String.format("%03d", taskId);
    return formatString;
  }
  
  public void addTask(Task task){//FIXME
    if(task.getTaskId() == null){
      task.setTaskId(generateTaskId());
    }else{ throw new IllegalArgumentException("Task is already in list: " + task.getTaskId());}
    if(!tasks.containsKey(task.getTaskId())){
      tasks.put(task.getTaskId(), task);
    }else{throw new IllegalArgumentException("TaskId not unique");}//not testable
  }
  public void deleteTask(String taskId){//FIXME
    tasks.remove(taskId);
  }
  public void updateTask(String taskId, String name, String desc){
    Task task = tasks.get(taskId);
    if (task != null) {
      task.setName(name);
      task.setDescription(desc);
      tasks.put(taskId, task);
    }else{
      throw new IllegalArgumentException("Task not found: " + taskId);
    }
  }
  public Task getTask(String taskId){
    return tasks.get(taskId);
  }
  public void printTasks(){
    for(Task task : tasks.values()){
      task.printContactDetails();
    }
  }
  public Map<String, Task> getAllTasks() {
        return tasks;
    }

  public void clearTasks() {
      tasks.clear(); // Clear the tasks map
  }
}