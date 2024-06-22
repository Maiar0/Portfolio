import java.util.HashMap;
import java.util.Map;

public class ContactService{
  //Singleton instance
  private static ContactService instance;
  private Map<String, Contact> contacts;
  private int contactId;
  
  //map to store contacts by contactId
  private ContactService(){
    contacts = new HashMap<>();
    contactId = 0;
  }
  //returns instance
  public static ContactService getInstance(){
    if(instance == null){
      instance = new ContactService();
    }
    return instance;
  }
  //generateContactId
  public String generateContactId() {
    contactId++;
    String formatString = String.format("%03d", contactId);
    return formatString;
  }
  //addcontact
  public void addContact(Contact contact){
    if(contact.getContactId() == null) {
      contact.setContactId(generateContactId());
    }else {throw new IllegalArgumentException("Contact is already in list: " + contact.getContactId());}
    if(!contacts.containsKey(contact.getContactId())) {
      contacts.put(contact.getContactId(), contact);
    }else {throw new IllegalArgumentException("ContactId not unique");}//not testable
  }
  //remove contact
  public void deleteContact(String contactId){
    contacts.remove(contactId);
  }
  //update contact 
  public void updateContact(String contactId, String firstName, String lastName, String phone, String address) {
      Contact contact = contacts.get(contactId);
      if (contact != null) {
          contact.setFirstName(firstName);
          contact.setLastName(lastName);
          contact.setPhone(phone);
          contact.setAddress(address);
          contacts.put(contactId, contact);
      } else {
          throw new IllegalArgumentException("Contact not found: " + contactId);
      }
  }


  public Contact getContact(String contactId){
    return contacts.get(contactId);
  }

  // Method to print all contacts
  public void printContacts() {
      System.out.println("All Contacts:");
      for (Contact contact : contacts.values()) {
          contact.printContactDetails();
       }
  }
    // Getter for contacts (if needed)
    public Map<String, Contact> getAllContacts() {
        return contacts;
    }
    public void clearContacts() {
        contacts.clear(); // Clear the contacts map
    }
}