package logical;

public class Main {

	public static void main(String[] args) {
		 Correo correo = new Correo();   
		 Consumidor consumidor = new Consumidor(correo);  
		 Productor productor = new Productor(correo);  
		 consumidor.start();  
		 productor.start(); 

	}

}
