public class Task{
  private String name;
  private String description;
  private String taskId;//managed by TaskService

  public Task(String name, String description) {
    if(name == null || name.length() > 20){
      throw new IllegalArgumentException("Invalid name length");
    }
    if(description == null || description.length() > 50){
      throw new IllegalArgumentException("Invalid description length");
    }
    this.name = name;
    this.description = description;
  }

  public String getName() {
    return name;
  }

  public String getDescription() {
    return description;
  }
  public String getTaskId() {
    return taskId;
  }

  public void setName(String name) {
    if(name == null || name.length() > 20 || name.isEmpty()){
     throw new IllegalArgumentException("Invalid name length"); 
    }else{
      this.name = name;
    }
  }

  public void setDescription(String description) {
    if(description == null || description.length() > 50 || description.isEmpty()){
      throw new IllegalArgumentException("Invalid description length");
    }else{
      this.description = description;
    }
  }
  public void setTaskId(String taskId) {
    TaskService taskService = TaskService.getInstance();
    if(taskService.getAllTasks().containsKey(taskId) || taskId == null || taskId.isEmpty() || taskId.length() > 10){
      throw new IllegalArgumentException("Invalid task ID");
    }else{
      this.taskId = taskId;
    }
  }
  
  public void printContactDetails(){
    System.out.println("Task ID: " + taskId);
    System.out.println("Task Name: " + name);
    System.out.println("Task Description: " + description);
    System.out.println();
  }

}