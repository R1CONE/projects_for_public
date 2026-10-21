
const przyciski = document.querySelectorAll(".nav-item");
const text = document.querySelector(".content-article");

const tematy = [
    {
        naglowek: "Start",
        opis: "Witaj w naszej kawiarni! Odkryj świat aromatycznej kawy i świetnej atmosfery."
    },
    {
        naglowek: "O firmie",
        opis: "Jesteśmy pasjonatami kawy. Tworzymy miejsce, w którym każdy może odpocząć i delektować się ulubionym napojem."
    },
    {
        naglowek: "Oferta",
        opis: "Oferujemy espresso, cappuccino, latte, herbatę oraz pyszne ciasta i desery."
    },
    {
        naglowek: "Cennik",
        opis: "Espresso – 8 zł, cappuccino – 12 zł, latte – 14 zł, herbata – 10 zł."
    },
    {
        naglowek: "Portfolio",
        opis: "Poznaj naszą kawiarnię, przytulne wnętrze oraz napoje przygotowywane przez naszych baristów."
    },
    {
        naglowek: "Kontakt",
        opis: "Zapraszamy do naszej kawiarni! Skontaktuj się z nami, aby dowiedzieć się więcej."
    }
];

przyciski.forEach((przycisk, index) => {
    przycisk.addEventListener("click", () => {
        text.innerHTML = `
            <h1 class="main-heading">${tematy[index].naglowek}</h1>
            <p>${tematy[index].opis}</p>
        `;
    });
});
