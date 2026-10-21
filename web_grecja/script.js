
const przyciski = document.querySelectorAll(".nav-item");
const text = document.querySelector(".content-article");

const tematy = [
    {
        naglowek: "Start",
        opis: "hello "
    },
    {
        naglowek: "O firmie",
        opis: "firma."
    },
    {
        naglowek: "Oferta",
        opis: "Oferty."
    },
    {
        naglowek: "Cennik",
        opis: "cenniki"
    },
    {
        naglowek: "Portfolio",
        opis: "portfolio"
    },
    {
        naglowek: "Kontakt",
        opis: "+454545454"
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


