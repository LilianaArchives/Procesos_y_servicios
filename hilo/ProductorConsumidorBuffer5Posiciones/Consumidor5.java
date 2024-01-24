package ProductorConsumidorBuffer5Posiciones;

public class Consumidor5 extends Thread {
    private Cola5 cola;
    private int n;

    //Constructor recibe la cola y un id para el hilo consumidor
    public Consumidor5(Cola5 c, int n) {
        cola = c;
        this.n = n;
    }

    public void run() {
        int valor = 0;
        for (int i = 1; i <= 25; i++) {
            valor = cola.get(); //recoge el número
            System.out.println("Hilo Consumidor " + n
                    + " consume: " + valor);
            try {
                sleep(100);
            } catch (InterruptedException e) { }
        }
    }
}
