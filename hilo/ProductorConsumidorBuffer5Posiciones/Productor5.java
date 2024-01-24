package ProductorConsumidorBuffer5Posiciones;


public class Productor5 extends Thread {
    private Cola5 cola;
    private int n;

    //Constructor recibe la cola y un id para el hilo prodcutor
    public Productor5(Cola5 c, int n) {
        cola = c;
        this.n = n;
    }

    public void run() {
        for (int i = 1; i <= 100 ; i++) {
            cola.put(i); //escribe el número en la cola
            System.out.println(" Hilo Productor " + n
                    + " produce: " + i);
            /**
            try {
                sleep(10);
            } catch (InterruptedException e) { }
            **/

        }
    }
}
