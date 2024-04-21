import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.util.Map;

public class ContactServiceTest {
  
    private ContactService contactService = ContactService.getInstance();//replit wont run the set up for some reason
 
    @BeforeEach
    public void setUp() {
      contactService = ContactService.getInstance();
    }

    @Test
    public void testAddContact() {
        Contact contact = new Contact("John", "Doe", "1234567890", "123 Main St");
        Contact contact2 = new Contact("Jane", "Smith", "0987654321", "456 Elm St");
        contactService.addContact(contact);
        contactService.addContact(contact2);
        //check if added
        Map<String, Contact> allContacts = contactService.getAllContacts();
        assertTrue(allContacts.containsKey(contact.getContactId()));
        //check if duplicate ID
        assertThrows(IllegalArgumentException.class, () -> contact2.setContactId(contact.getContactId()));
        //duplicate object 
        assertThrows(IllegalArgumentException.class, () -> contactService.addContact(contact));
        
    }

    @Test
    public void testDeleteContact() {
        Contact contact = new Contact("John", "Doe", "1234567890", "123 Main St");
        contactService.addContact(contact);
        contactService.deleteContact(contact.getContactId());
        Map<String, Contact> allContacts = contactService.getAllContacts();
        assertFalse(allContacts.containsKey(contact.getContactId()));
    }

    @Test
    public void testUpdateContact() {
        Contact contact = new Contact("John", "Doe", "1234567890", "123 Main St");
        contactService.addContact(contact);
        String contactId = contact.getContactId();
        contactService.updateContact(contactId, "Jane", "Smith", "0987654321", "456 Elm St");
        Contact updatedContact = contactService.getContact(contactId);
        assertEquals("Jane", updatedContact.getFirstName());
        assertEquals("Smith", updatedContact.getLastName());
        assertEquals("0987654321", updatedContact.getPhone());
        assertEquals("456 Elm St", updatedContact.getAddress());
    }
    
    @Test
    public void testUpdateNonexistentContact() {
        // Attempting to update a non-existent contact should fail
        assertThrows(IllegalArgumentException.class, () -> 
        	contactService.updateContact("!exist", "Jane", "Smith", "0987654321", "456 Elm St"));

    }

    @Test
    public void testGetContact() {
        Contact contact = new Contact("John", "Doe", "1234567890", "123 Main St");
        contactService.addContact(contact);
        Contact retrievedContact = contactService.getContact(contact.getContactId());
        assertNotNull(retrievedContact);
        assertEquals(contact.getContactId(), retrievedContact.getContactId());
    }
    
    @Test
    public void testClearContacts() {
    	Contact contact = new Contact("John", "Doe", "1234567890", "123 Main St");
    	Contact contact2 = new Contact("John", "Doe", "1234567890", "123 Main St");

        // Add some contacts to the map
        contactService.addContact(contact);
        contactService.addContact(contact2);
        contactService.clearContacts();//clear them
        assertTrue(contactService.getAllContacts().isEmpty());
    }
    
    @Test
    public void testPrintContacts() {
        // Given
        contactService.clearContacts();
        Contact contact1 = new Contact("John", "Doe", "1234567890", "123 Main St");
        Contact contact2 = new Contact("Jane", "Smith", "9876543210", "456 Elm St");
        contactService.addContact(contact1);
        contactService.addContact(contact2);

        // Redirect standard output stream
        ByteArrayOutputStream outputStreamCaptor = new ByteArrayOutputStream();
        System.setOut(new PrintStream(outputStreamCaptor));

        // When
        contactService.printContacts();

        // Then
        String[] lines = outputStreamCaptor.toString().split("\\r?\\n");
        assertEquals("All Contacts:", lines[0]);
        assertEquals("Contact ID: " + contact1.getContactId(), lines[1]);
        assertEquals("First Name: John", lines[2]);
        assertEquals("Last Name: Doe", lines[3]);
        assertEquals("Phone: 1234567890", lines[4]);
        assertEquals("Address: 123 Main St", lines[5]);
        assertEquals("", lines[6]); // Empty line after printing contact 1
        assertEquals("Contact ID: " + contact2.getContactId(), lines[7]);
        assertEquals("First Name: Jane", lines[8]);
        assertEquals("Last Name: Smith", lines[9]);
        assertEquals("Phone: 9876543210", lines[10]);
        assertEquals("Address: 456 Elm St", lines[11]);
    }
}
