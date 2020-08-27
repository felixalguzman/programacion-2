package logical;

public class Productor extends Thread {  
    private Correo correo;  
    public Productor(Correo correo) {  
         this.correo = correo;  
    }  
    public void run() {  
         String [] mensajes = {"primer mensaje", "segundo mensaje", "tercer mensaje"};  
         for (String men:mensajes) {
              correo.enviar(men);  
         }  
    }       
}  
