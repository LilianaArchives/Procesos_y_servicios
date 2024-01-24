package ProductorConsumidorBuffer5Posiciones;

public class Produc_Consum5 {
    public static void main(String[] args) {
        Cola5 cola = new Cola5();

        Productor5 prod = new Productor5(cola, 1);
        Consumidor5 cons1 = new Consumidor5(cola, 2);
        Consumidor5 cons2 = new Consumidor5(cola, 3);
        Consumidor5 cons3 = new Consumidor5(cola, 4);
        Consumidor5 cons4 = new Consumidor5(cola, 5);

        prod.start();
        cons1.start();
        cons2.start();
        cons3.start();
        cons4.start();
    }
}
