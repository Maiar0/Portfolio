import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach; 
import java.util.Map;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

public class AppointmentServiceTest {
  AppointmentService appointmentService = AppointmentService.getInstance();

  @BeforeEach
  public void setUp() {
      appointmentService = AppointmentService.getInstance();
  } 
  
  @Test
  public void testAddAppt(){
    Appointment appt = new Appointment("2025-04-01", "Meeting with client");
    Appointment appt2 = new Appointment("2025-04-01", "Meeting with client");
    appointmentService.addAppointment(appt);
    appointmentService.addAppointment(appt2);
    //checks if in map
    assertTrue(appointmentService.getAllAppointments().containsKey(appt.getApptId()));
    //check if duplicate ID
    assertThrows(IllegalArgumentException.class, () -> appt2.setApptId(appt.getApptId()));
    //duplicate object 
    assertThrows(IllegalArgumentException.class, () -> appointmentService.addAppointment(appt));
  }

    @Test
    public void testDeleteAppointment() {
        Appointment appointment = new Appointment("2025-04-01", "Meeting with client");
        appointmentService.addAppointment(appointment);
        assertDoesNotThrow(() -> appointmentService.deleteAppointment(appointment.getApptId()));
        assertFalse(appointmentService.getAllAppointments().containsValue(appointment));
    }

    @Test
    public void testUpdateAppointment() {
        Appointment appointment = new Appointment("2025-04-01", "Meeting with client");
        appointmentService.addAppointment(appointment);
        String newDate = "2025-04-02";
        String newDesc = "Updated description";
        assertDoesNotThrow(() -> appointmentService.updateAppointment(appointment.getApptId(), newDate, newDesc));
        assertEquals(newDate, appointmentService.getAppointment(appointment.getApptId()).getApptDate());
        assertEquals(newDesc, appointmentService.getAppointment(appointment.getApptId()).getApptDesc());
    }
    @Test
    public void testUpdateAppointment_Error(){
      assertThrows(IllegalArgumentException.class, () -> 
      appointmentService.updateAppointment("!found", "2025-04-02", "Updated description"));
    }

    @Test
    public void testGetAppointment() {
        Appointment appointment = new Appointment("2025-04-01", "Meeting with client");
        appointmentService.addAppointment(appointment);
        assertEquals(appointment, appointmentService.getAppointment(appointment.getApptId()));
    }

    @Test
    public void testGenerateAppointmentId() {
        String apptId1 = appointmentService.generateAppointmentId();
        String apptId2 = appointmentService.generateAppointmentId();
        assertNotEquals(apptId1, apptId2);
    }

    @Test
    public void testGetAllAppointments() {
        Appointment appointment1 = new Appointment("2025-04-01", "Meeting with client");
        Appointment appointment2 = new Appointment("2025-04-02", "Follow-up call");
        appointmentService.addAppointment(appointment1);
        appointmentService.addAppointment(appointment2);
        Map<String, Appointment> appointments = appointmentService.getAllAppointments();
        assertTrue(appointments.containsValue(appointment1));
        assertTrue(appointments.containsValue(appointment2));
    }
    
    @Test
    public void testClearAppointments() {
        // Add some appointments
        Appointment appointment1 = new Appointment( "2025-04-07", "Meeting 1");
        Appointment appointment2 = new Appointment( "2025-04-08", "Meeting 2");
        appointmentService.addAppointment(appointment1);
        appointmentService.addAppointment(appointment2);

        // Check that appointments are present before clearing
        Map<String, Appointment> appointmentsBeforeClear = appointmentService.getAllAppointments();
        assertFalse(appointmentsBeforeClear.isEmpty());

        // Clear appointments
        appointmentService.clearAppointments();

        // Check that appointments are cleared
        Map<String, Appointment> appointmentsAfterClear = appointmentService.getAllAppointments();
        assertTrue(appointmentsAfterClear.isEmpty());
    }
    
  @Test
  public void testPrintAppointments() {
      // Given
      appointmentService.clearAppointments();
      Appointment appointment1 = new Appointment("2025-04-01", "Meeting with client");
      Appointment appointment2 = new Appointment("2025-04-02", "Team meeting");
      appointmentService.addAppointment(appointment1);
      appointmentService.addAppointment(appointment2);

      // Redirect standard output stream
      ByteArrayOutputStream outputStreamCaptor = new ByteArrayOutputStream();
      System.setOut(new PrintStream(outputStreamCaptor));

      // When
      appointmentService.printAppointments();

      // Then
      String[] lines = outputStreamCaptor.toString().split("\\r?\\n");
      assertEquals("Appointment ID: " + appointment1.getApptId(), lines[0]);
      assertEquals("Appointment Date: 2025-04-01", lines[1]);
      assertEquals("Appointment Description: Meeting with client", lines[2]);
      assertEquals("", lines[3]); // Empty line after printing appointment 1
      assertEquals("Appointment ID: " + appointment2.getApptId(), lines[4]);
      assertEquals("Appointment Date: 2025-04-02", lines[5]);
      assertEquals("Appointment Description: Team meeting", lines[6]);
  }

  
}
