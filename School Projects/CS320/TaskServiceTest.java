import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.util.Map;
import static org.junit.jupiter.api.Assertions.*;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

public class TaskServiceTest {

    private TaskService taskService = TaskService.getInstance();//replit wont run the set up for some reason

    @BeforeEach
    public void setUp() {
        taskService = TaskService.getInstance();
    }

    @Test
    public void testGenerateTaskId() {
        // Act
        String taskId1 = taskService.generateTaskId();
        String taskId2 = taskService.generateTaskId();

        // Assert
        assertNotNull(taskId1);
        assertNotNull(taskId2);
        assertNotEquals(taskId1, taskId2); // Ensure generated task IDs are unique
    }

    @Test
    public void testAddTask() {
        Task task = new Task("AddTask", "Sample Description");
        Task task2 = new Task("AddTask2", "Sample Description");
        taskService.addTask(task);
        taskService.addTask(task2);
        Map<String, Task> tasks = taskService.getAllTasks();
        //if task added
        assertTrue(tasks.containsKey(task.getTaskId()));
        //check if duplicate ID
        assertThrows(IllegalArgumentException.class, () -> task2.setTaskId(task.getTaskId()));
        //duplicate object
        assertThrows(IllegalArgumentException.class, () -> taskService.addTask(task));
    }
  
    @Test
    public void testDeleteTask() {
        Task task = new Task("Delete Task", "Sample Description");
        taskService.addTask(task);
        taskService.deleteTask(task.getTaskId());
        
        assertFalse(taskService.getAllTasks().containsKey(task.getTaskId()));
    }

    @Test
    public void testUpdateTask() {
        Task task = new Task("Sample Task", "Sample Description");
        taskService.addTask(task);
        String newName = "Updated Task Name";
        String newDescription = "Updated Task Description";
        taskService.updateTask(task.getTaskId(), newName, newDescription);
        Task updatedTask = taskService.getTask(task.getTaskId());
        assertEquals(newName, updatedTask.getName());
        assertEquals(newDescription, updatedTask.getDescription());
    }
    @Test
    public void testUpdateTask_Error() {
        // Attempting to update a non-existent contact should fail
      assertThrows(IllegalArgumentException.class, () -> 
      	taskService.updateTask("!found", "Updated Task Name", "Updated Task Description"));

    }

    @Test
    public void testGetTask() {
        Task task = new Task("Sample Task", "Sample Description");
        taskService.addTask(task);
        Task retrievedTask = taskService.getTask(task.getTaskId());
        
        assertNotNull(retrievedTask);
        assertEquals(task, retrievedTask);
    }
    
    @Test
    public void testClearContacts() {
    	//add some tasks
    	Task task = new Task("AddTask", "Sample Description");
        Task task2 = new Task("AddTask2", "Sample Description");
        taskService.addTask(task);
        taskService.addTask(task2);
        taskService.clearTasks();//clear them
        assertTrue(taskService.getAllTasks().isEmpty());
    }
    
  @Test
  public void testPrintTasks() {
  final ByteArrayOutputStream outputStreamCaptor = new ByteArrayOutputStream();
  System.setOut(new PrintStream(outputStreamCaptor));
      // Given
      taskService.clearTasks();
      Task task1 = new Task("Task 1", "Task 1 Description");
      Task task2 = new Task("Task 2", "Task 2 Description");
      taskService.addTask(task1);
      taskService.addTask(task2);

      // When
      taskService.printTasks();

      // Then
      String[] lines = outputStreamCaptor.toString().split("\\r?\\n");
      assertAll(
          () -> assertEquals("Task ID: "+task1.getTaskId(), lines[0]),
          () -> assertEquals("Task Name: Task 1", lines[1]),
          () -> assertEquals("Task Description: Task 1 Description", lines[2]),
          () -> assertEquals("", lines[3]), // Empty line after printing task 1
          () -> assertEquals("Task ID: "+task2.getTaskId(), lines[4]),
          () -> assertEquals("Task Name: Task 2", lines[5]),
          () -> assertEquals("Task Description: Task 2 Description", lines[6])
      );
  }
}
