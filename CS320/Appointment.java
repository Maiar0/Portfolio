import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
public class Appointment{
  private String apptId;//managed by AppointmentService
  private String apptDate;
  private String apptDesc;
  
  public Appointment(String apptDate, String apptDesc){
    LocalDate currentDate = LocalDate.now();
    if(apptDate == null){
      throw new IllegalArgumentException("Invalid date");
    }
    if(apptDesc == null || apptDesc.length() > 50){
      throw new IllegalArgumentException("Invalid time length");
    }
    try{
      LocalDate date = LocalDate.parse(apptDate);
      if(date.isBefore(currentDate)){
        throw new IllegalArgumentException("Appointment date cannot be in the past");
      }}
    catch(DateTimeParseException e){
    	throw new IllegalArgumentException("Invalid date format. Please enter a date in the format YYYY-MM-DD.");
    }
    
    
    this.apptDate = apptDate;
    this.apptDesc = apptDesc;
  }

  //getters
  public String getApptId(){
    return apptId;
  }
  public String getApptDate(){
    return apptDate;
  }
  public String getApptDesc(){
    return apptDesc;
  }
  
  //setters
  public void setApptId(String apptId){
    AppointmentService apptService = AppointmentService.getInstance();
    if(apptService.getAllAppointments().containsKey(apptId) || apptId == null || apptId.isEmpty() || apptId.length() > 10){
      throw new IllegalArgumentException("Invalid apptId");
    }else{
      this.apptId = apptId;
    }
  }
  
  public void setApptDate(String apptDate){
    LocalDate currentDate = LocalDate.now();
    try{
      LocalDate date = LocalDate.parse(apptDate);
      if(date.isBefore(currentDate)){
        throw new IllegalArgumentException("Appointment date cannot be in the past");
      }else{
          this.apptDate = apptDate;
      }}
    catch(DateTimeParseException e){
    	throw new IllegalArgumentException("Invalid date format. Please enter a date in the format YYYY-MM-DD.");
    }
    catch(NullPointerException e) {
    	throw new IllegalArgumentException("Invalid date Null");
    }
  }
  
  public void setApptDesc(String apptDesc){
    if(apptDesc == null || apptDesc.length() > 50){
      throw new IllegalArgumentException("Invalid time length");
    }else{
      this.apptDesc = apptDesc;
    }
  }
  public void printAppointmentDetails(){
    System.out.println("Appointment ID: " + apptId);
    System.out.println("Appointment Date: " + apptDate);
    System.out.println("Appointment Description: " + apptDesc);
    System.out.println();
  }
}