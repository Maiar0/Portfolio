import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach; 
import java.time.LocalDate;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.time.format.DateTimeParseException;

public class AppointmentTest {
	
    @Test
    public void testConstructor() {
        String validDate = "2025-04-01";
        String validDesc = "Meeting with client";
        String invalidDate = "asdasdasd"; // Incorrect date format
        String pastDate = "2022-01-01";
        String longDesc = "123456789012345678901234567890123456789012345678901";
        assertDoesNotThrow(() -> new Appointment(validDate, validDesc));
        assertThrows(IllegalArgumentException.class, () -> new Appointment(invalidDate, validDesc));
        assertThrows(IllegalArgumentException.class, () -> new Appointment(pastDate, validDesc));
        assertThrows(IllegalArgumentException.class, () -> new Appointment(null, validDesc));
        assertThrows(IllegalArgumentException.class, () -> new Appointment(validDate, longDesc));
        assertThrows(IllegalArgumentException.class, () -> new Appointment(validDate, null));
    }
    

    @Test
    public void testSetID() {
    	//Test for illegal ContactID
    	Appointment appt = new Appointment("2025-04-01", "Meeting with client");
    	
    	//too long
    	assertThrows(IllegalArgumentException.class, () -> appt.setApptId("12345678901"));
    	//null
    	assertThrows(IllegalArgumentException.class, () -> appt.setApptId(null));
    	//too empty
    	assertThrows(IllegalArgumentException.class, () -> appt.setApptId(""));
    	//valid
        appt.setApptId("987654324");
        assertEquals("987654324", appt.getApptId());
    }
  
    @Test
    public void testSetApptDate() {
        Appointment appointment = new Appointment("2025-04-01", "Meeting with client");
        String newDate = "2025-04-02";
        String pastDate = "2022-01-01";
        String invalidDate = "asdasd";
        assertThrows(IllegalArgumentException.class, () -> appointment.setApptDate(pastDate));
        assertThrows(IllegalArgumentException.class, () -> appointment.setApptDate(invalidDate));
        assertThrows(IllegalArgumentException.class, () -> appointment.setApptDate(null));
        appointment.setApptDesc(newDate);
        assertEquals(newDate, appointment.getApptDesc());
    }

    @Test
    public void testSetApptDesc() {
        Appointment appointment = new Appointment("2025-04-01", "Meeting with client");
        String longDesc = "123456789 123456789 123456789 123456789 123456789 1";
        //too long
        assertThrows(IllegalArgumentException.class, () -> appointment.setApptDesc(longDesc));
        //null
        assertThrows(IllegalArgumentException.class, () -> appointment.setApptDesc(null));
        //valid
        String newDesc = "Updated description";
        appointment.setApptDesc(newDesc);
        assertEquals(newDesc, appointment.getApptDesc());
    }
    //print method tested throw Service class
    /*@Test
    public void testPrintAppointmentDetails() {
        // Given
        String validDate = "2025-04-01";
        String validDesc = "Meeting with client";
        Appointment appointment = new Appointment(validDate, validDesc);

        // Redirect standard output stream
        ByteArrayOutputStream outputStreamCaptor = new ByteArrayOutputStream();
        System.setOut(new PrintStream(outputStreamCaptor));

        // When
        appointment.printAppointmentDetails();

        // Then
        String expectedOutput = "Appointment ID: null\n" +
                                "Appointment Date: 2024-04-01\n" +
                                "Appointment Description: Meeting with client\n\n";
        assertEquals(expectedOutput, outputStreamCaptor.toString());
    }*/
}
