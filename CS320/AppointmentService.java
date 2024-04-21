import java.util.HashMap;
import java.util.Map;

public class AppointmentService{
  private static AppointmentService instance;
  private Map<String, Appointment> appointments;
  private int appointmentId;

  private AppointmentService(){
    appointments = new HashMap<>();
    appointmentId = 0;
  }
  public static AppointmentService getInstance(){
    if(instance == null){
      instance = new AppointmentService();
    }
    return instance;
  }

  public String generateAppointmentId(){
    appointmentId++;
    String formatString = String.format("%03d", appointmentId);
    return formatString;
  }
  
  public void addAppointment(Appointment appointment){
    if(appointment.getApptId() == null){
      appointment.setApptId(generateAppointmentId());
    }else{throw new IllegalArgumentException("Appointment is already in list: " + appointment.getApptId());}
    if(!appointments.containsKey(appointment.getApptId())){
      appointments.put(appointment.getApptId(), appointment);
    }else{throw new IllegalArgumentException("AppointmentId not unique");}//cant be tested bc we have no way to reach this without throwing an error else where
  }
  
  public void deleteAppointment(String appointmentId){
    appointments.remove(appointmentId);
  }
  
  public void updateAppointment(String appointmentId, String apptDate, String apptDesc){
    Appointment appointment = appointments.get(appointmentId);
    if(appointment != null){
      appointment.setApptDate(apptDate);
      appointment.setApptDesc(apptDesc);
    }else{
      throw new IllegalArgumentException("Appointment not found");
    }
  }
  
  public Appointment getAppointment(String appointmentId){
    return appointments.get(appointmentId);
  }
  
  public void printAppointments(){
    for(Appointment appointment : appointments.values()){
      appointment.printAppointmentDetails();
    }
  }
  
  public Map<String, Appointment> getAllAppointments() {
        return appointments;
    }
  public void clearAppointments() {
        appointments.clear();
    }
}