public class HiloRunnableSumasRestasEjecutar {
    public static void main(String[] args) {
        new Thread(new HiloRunnableSumasRestas(100, "+")).start();
        new Thread(new HiloRunnableSumasRestas(100, "-")).start();
        new Thread(new HiloRunnableSumasRestas(1, "+")).start();
        new Thread(new HiloRunnableSumasRestas(1, "-")).start();
    }
}
