public class Contact{
  //intialize variables
  private String contactId;
  private String firstName;
  private String lastName;
  private String phone;
  private String address;

  public Contact(String firstName, String lastName, String phone, String address){
    //catch errors in formatting 
    if (firstName == null || firstName.isEmpty() || firstName.length() > 10) {
        throw new IllegalArgumentException("Invalid first name: must not be null, empty, or exceed 10 characters.");
    }
    if (lastName == null || lastName.isEmpty() || lastName.length() > 10) {
        throw new IllegalArgumentException("Invalid last name: must not be null, empty, or exceed 10 characters.");
    }
    if (phone == null || phone.isEmpty() || phone.length() != 10) {
        throw new IllegalArgumentException("Invalid phone number: must be exactly 10 digits long.");
    }
    if (address == null || address.isEmpty() || address.length() > 30) {
        throw new IllegalArgumentException("Invalid address: must not be null, empty, or exceed 30 characters.");
    }
    this.firstName = firstName;
    this.lastName = lastName;
    this.phone = phone;
    this.address = address;
  }
  //getters
  public String getContactId(){
    return contactId;
  }
  public String getFirstName(){
    return firstName;
  }
  public String getLastName(){
    return lastName;
  }
  public String getPhone(){
    return phone;
  }
  public String getAddress(){
    return address;
  }
 //setters
  public void setContactId(String contactId) {
    ContactService contactService = ContactService.getInstance();
    if(contactService.getAllContacts().containsKey(contactId) || contactId == null || contactId.isEmpty() || contactId.length() > 10){
      throw new IllegalArgumentException("Invalid contact ID");
    }else{
      this.contactId = contactId;
    }
  }
  public void setFirstName(String firstName){
    if(firstName != null && !firstName.isEmpty() && firstName.length()<= 10){
      this.firstName = firstName;
    }else{throw new IllegalArgumentException("Invalid first name length");}
  }

  public void setLastName(String lastName){
    if(lastName != null && !lastName.isEmpty() && lastName.length() <= 10){
      this.lastName = lastName;
    }else{throw new IllegalArgumentException("Invalid last name length");}
  }
  public void setPhone(String phone){
    if(phone != null && !phone.isEmpty() && phone.length() == 10){
      this.phone = phone;
    }else{throw new IllegalArgumentException("Invalid phone number");}
  }
  public void setAddress(String address){
    if(address != null && !address.isEmpty() && address.length() <= 30){
    this.address = address;
    }else{throw new IllegalArgumentException("Invalid Address");}
  }

  // Method to print contact details
  public void printContactDetails() {
      System.out.println("Contact ID: " + contactId);
      System.out.println("First Name: " + firstName);
      System.out.println("Last Name: " + lastName);
      System.out.println("Phone: " + phone);
      System.out.println("Address: " + address);
      System.out.println();
  }
}