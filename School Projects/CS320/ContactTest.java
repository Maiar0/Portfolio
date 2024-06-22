import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

public class ContactTest {

    @Test
    public void testValidContactCreation() {
        Contact contact = new Contact("John", "Doe", "1234567890", "123 Main St");
        assertEquals("John", contact.getFirstName());
        assertEquals("Doe", contact.getLastName());
        assertEquals("1234567890", contact.getPhone());
        assertEquals("123 Main St", contact.getAddress());
    }
    @Test //test null Constructor instantiation
    public void testConstructor_null() {
    	//Test for null first name
    	assertThrows(IllegalArgumentException.class, () -> {
            new Contact(null, "Doe", "1234567890", "123 Main St");
          });
    	//Test for null last name
    	assertThrows(IllegalArgumentException.class, () -> {
            new Contact("John", null, "1234567890", "123 Main St");
          });
    	//Test for null phone
    	assertThrows(IllegalArgumentException.class, () -> {
            new Contact("John", "Doe", null, "123 Main St");
          });
    	//Test for null address
    	assertThrows(IllegalArgumentException.class, () -> {
            new Contact("John", "Doe", "1234567890", null);
          });
    }
  //test empty Constructor instantiation
    @Test
    public void testConstructor_empty() {
    	//Test for empty first name
    	assertThrows(IllegalArgumentException.class, () -> {
            new Contact("", "Doe", "1234567890", "123 Main St");
          });
    	//Test for empty last name
    	assertThrows(IllegalArgumentException.class, () -> {
            new Contact("John", "", "1234567890", "123 Main St");
          });
    	//Test for empty phone
    	assertThrows(IllegalArgumentException.class, () -> {
            new Contact("John", "Doe", "", "123 Main St");
          });
    	//Test for empty address
    	assertThrows(IllegalArgumentException.class, () -> {
            new Contact("John", "Doe", "1234567890", "");
          });
    }
    
  //test illegal Constructor instantiation
    @Test
    public void testConstructor_illegal() {
    	//Test for illegal first name
    	assertThrows(IllegalArgumentException.class, () -> {
            new Contact("JohnDoe1234", "Doe", "1234567890", "123 Main St");
          });
    	//Test for illegal last name
    	assertThrows(IllegalArgumentException.class, () -> {
            new Contact("John", "JohnDoe1234", "1234567890", "123 Main St");
          });
    	//Test for illegal phone (too long)
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("John", "Doe", "12345678901", "123 Main St");
        });
        //Test for illegal phone (too short)
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("John", "Doe", "123456789", "123 Main St");
        });
    	//Test for illegal address
    	assertThrows(IllegalArgumentException.class, () -> {
            new Contact("John", "Doe", "1234567890", "1234567890123456789012345678901");
          });
    }
    /*contactId is tested in ContactService and is fully managed there*/
    @Test
    public void testSetID() {
    	//Test for illegal ContactID
    	Contact contact = new Contact("John", "Doe", "1234567890", "123 Main St");
    	
    	//too long
    	assertThrows(IllegalArgumentException.class, () -> {
            contact.setContactId("12345678901");
          });
    	//null
    	assertThrows(IllegalArgumentException.class, () -> {
            contact.setContactId(null);
          });
    	//too empty
        assertThrows(IllegalArgumentException.class, () -> {
            contact.setContactId("");
        });
    	//valid
        contact.setContactId("987654324");
        assertEquals("987654324", contact.getContactId());
    }
    @Test
    public void testSetFirst() {
    	//Test for illegal first name
    	Contact contact = new Contact("John", "Doe", "1234567890", "123 Main St");
    	//too long
    	assertThrows(IllegalArgumentException.class, () -> {
            contact.setFirstName("JohnDoe1234");
          });
    	//null
    	assertThrows(IllegalArgumentException.class, () -> {
            contact.setFirstName(null);
          });
    	//too empty
        assertThrows(IllegalArgumentException.class, () -> {
            contact.setFirstName("");
        });
    	//valid
        contact.setFirstName("Alice");
        assertEquals("Alice", contact.getFirstName());
    }
    @Test
    public void testSetLast() {
    	//Test for illegal Last name
    	Contact contact = new Contact("John", "Doe", "1234567890", "123 Main St");
    	//too long
    	assertThrows(IllegalArgumentException.class, () -> {
            contact.setLastName("JohnDoe1234");
          });
    	//null
    	assertThrows(IllegalArgumentException.class, () -> {
            contact.setLastName(null);
          });
    	//too empty
        assertThrows(IllegalArgumentException.class, () -> {
            contact.setLastName("");
        });
    	//valid
        contact.setLastName("Alice");
        assertEquals("Alice", contact.getLastName());
    }
    @Test
    public void testSetPhone() {
    	//Test for illegal Phone
    	Contact contact = new Contact("John", "Doe", "1234567890", "123 Main St");
    	//too long
    	assertThrows(IllegalArgumentException.class, () -> {
            contact.setPhone("12345678901");
          });
    	//null
    	assertThrows(IllegalArgumentException.class, () -> {
            contact.setPhone(null);
          });
    	//too empty
        assertThrows(IllegalArgumentException.class, () -> {
            contact.setPhone("");
        });
    	//valid
        contact.setPhone("1234567891");
        assertEquals("1234567891", contact.getPhone());
    }
    @Test
    public void testSetAddress() {
    	//Test for illegal Address
    	Contact contact = new Contact("John", "Doe", "1234567890", "123 Main St");
    	//too long
    	assertThrows(IllegalArgumentException.class, () -> {
            contact.setAddress("1234567890123456789012345678901");
          });
    	//null
    	assertThrows(IllegalArgumentException.class, () -> {
            contact.setAddress(null);
          });
    	//too empty
        assertThrows(IllegalArgumentException.class, () -> {
            contact.setAddress("");
        });
    	//valid
        contact.setAddress("123456");
        assertEquals("123456", contact.getAddress());
    }
    
    //print method tested throw Service class
    /*@Test
    public void testPrintContactDetails() {
        // Given
        Contact contact = new Contact("John", "Doe", "1234567890", "123 Main St");
        contact.setContactId("001");

        // Redirect standard output stream
        ByteArrayOutputStream outputStreamCaptor = new ByteArrayOutputStream();
        System.setOut(new PrintStream(outputStreamCaptor));
        

        // When
        contact.printContactDetails();
        String expectedOutput = "Contact ID: " + contact.getContactId() + "\n" +
                                "First Name: " + contact.getFirstName() + "\n" +
                                "Last Name: " + contact.getLastName() + "\n" +
                                "Phone: " + contact.getPhone() + "\n" +
                                "Address: " + contact.getAddress() + "\n\n" ;
        String out = outputStreamCaptor.toString();
        // Then
        assertEquals(expectedOutput, out);
    }*/
}
