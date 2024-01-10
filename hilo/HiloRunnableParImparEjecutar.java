public class HiloRunnableParImparEjecutar {
    public static void main(String[] args) {
        new Thread(new HiloRunnableParImpar("XX")).start();
        new Thread(new HiloRunnableParImpar("YY")).start();
    }
}
