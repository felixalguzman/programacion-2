package logical;

public class Consumidor extends Thread {  
    private Correo correo;  
    
    public Consumidor(Correo correo) {  
         this. correo = correo;  
    }  
    public void run() {  
         String mensaje = "";  
         while (!correo.getBuzonCorreo().isEmpty()) {  
              mensaje = correo.recibir();  
              System.out.println(mensaje+" leido");  
         }  
    }  
}  