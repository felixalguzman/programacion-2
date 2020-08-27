package logical;

import java.util.ArrayList;

public class Correo {  
    private String mensaje;  
    //private boolean vacio = true;  
    private ArrayList<String> BuzonCorreo = new ArrayList<>();
    
    public synchronized String recibir() {  
         //Espera hasta que el mensaje este disponible, si el buzon esta vacio espera. 
         while(BuzonCorreo.isEmpty()){  
              try {  
                   wait();  
              } catch (InterruptedException e) {  
                   e.printStackTrace();  
              }                 
         }  
        // vacio=true;  
         notifyAll(); 
         System.out.println("Leyendo mensaje");
         mensaje = BuzonCorreo.get(0);
         BuzonCorreo.remove(0);
         return  mensaje; 
    }  
    public synchronized void enviar(String mensaje){  
         //Espera hasta que el mensaje sea leido  
         while(!BuzonCorreo.isEmpty()) {  
              try {  
                   wait();  //con esto mandamos al hilo a esperar pork el buzon tiene mensajes.
              } catch (InterruptedException e) {  
                   e.printStackTrace();  
              }  
         }  
       //  vacio = false;
         System.out.println("Llego mensaje");
         BuzonCorreo.add(mensaje);  
         notifyAll();  
    }
    
	public ArrayList<String> getBuzonCorreo() {
		return BuzonCorreo;
	}
	public void setBuzonCorreo(ArrayList<String> buzonCorreo) {
		BuzonCorreo = buzonCorreo;
	}  
} 
